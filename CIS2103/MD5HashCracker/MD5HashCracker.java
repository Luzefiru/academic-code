import java.security.MessageDigest;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.List;
import java.util.stream.Collectors;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicBoolean;

public class MD5HashCracker {
    private static final String CHARSET = "abcdefghijklmnopqrstuvwxyz";
    private static final int MIN_LENGTH = 7; // for permutation checking
    private static final int MAX_LENGTH = 8;
    private static String inputHash;

    private static final AtomicBoolean hashFound = new AtomicBoolean(false);

    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Usage: java MD5HashCracker [MD5_HASH]");
            System.exit(1);
        }

        inputHash = args[0];

        Thread fileLookupThread = new Thread(() -> {
            String filename = "rainbow_table.txt"; // Plaintext Rainbow Table of `hash:value` pairs
            String plaintext = lookupHashInFile(filename, inputHash);
            if (plaintext != null) {
                System.out.println("[!] Hash Found (txt)   : " + plaintext);
                hashFound.set(true);
            } else {
                System.out.println("[x] Not Found (txt)    :");
            }
        });

        Thread webLookupThread = new Thread(() -> {
            String url = "https://raw.githubusercontent.com/Luzefiru/academic-code/main/CIS2103/md5/wordlist.txt"; // Online wordlist raw file
            if (checkUrl(url)) {
                List<String> words = fetchWordsFromUrl(url);
                for (String word : words) {
                  if (hashFound.get()) {
                    break;
                  }
                    if (getMd5(word).equals(inputHash)) {
                        System.out.println("[!] Hash Found (web)   : " + word);
                        hashFound.set(true);
                        break;
                    } else {
                        System.out.println("[x] Not Found (web)    : " + word);
                    }
                }
            } else {
                System.out.println("Error: Cannot Reach " + url);
            }
        });

        Thread permutationThread = new Thread(() -> {
            checkPermutations();
        });
        
        fileLookupThread.start();
        webLookupThread.start();
        permutationThread.start();

        try {
            fileLookupThread.join();
            webLookupThread.join();
            permutationThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        if (!hashFound.get()) {
            System.out.println("Hash not found in the file, web, or through permutations.");
        }
    }

    public static String lookupHashInFile(String filename, String inputHash) {
        BufferedReader reader;
        try {
            reader = new BufferedReader(new FileReader(filename));
            String line;
            while ((line = reader.readLine()) != null) {
                if (hashFound.get()) {
                    reader.close();
                    return null; // Exit early if the hash has been found
                }
                String[] parts = line.split(":");
                if (parts.length == 2) {
                    String hash = parts[0];
                    String plaintext = parts[1];
                    if (hash.equals(inputHash)) {
                        reader.close();
                        return plaintext;
                    }
                }
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null; // Hash not found in the file
    }

    private static boolean checkUrl(String urlStr) {
        try {
            URL url = new URL(urlStr);
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.setRequestMethod("HEAD");
            int responseCode = connection.getResponseCode();
            return responseCode == HttpURLConnection.HTTP_OK;
        } catch (Exception e) {
            return false;
        }
    }

    private static List<String> fetchWordsFromUrl(String urlStr) {
        try {
            URL url = new URL(urlStr);
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
            return reader.lines().collect(Collectors.toList());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private static String getMd5(String input) {
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] bytes = md.digest(input.getBytes("UTF-8"));
            StringBuilder result = new StringBuilder();
            for (byte b : bytes) {
                result.append(String.format("%02x", b));
            }
            return result.toString();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private static void checkPermutations() {
        ExecutorService executor = Executors.newFixedThreadPool(4);

        for (int length = MIN_LENGTH; length <= MAX_LENGTH; length++) {
            char[] password = new char[length];
            if (bruteForce(password, 0, length, executor)) {
                break;
            }
        }

        executor.shutdown();

        if (!hashFound.get()) {
            System.out.println("The MD5 cannot be dehashed.");
        }
    }

     private static boolean bruteForce(char[] password, int position, int length, ExecutorService executor) {
        if (hashFound.get()) {
            return true;
        }
 
        if (position == length) {
            String candidate = new String(password);
            String hash = getMd5(candidate);
            if (hash.equals(inputHash)) {
                hashFound.set(true);
                System.out.println("The dehashed MD5: " + candidate);
                return true;
            }
            return false;
        }
 
        for (int i = 0; i < CHARSET.length(); i++) {
            password[position] = CHARSET.charAt(i);
            if (bruteForce(password, position + 1, length, executor)) {
                return true;
            }
        }
 
        return false;
    }
}