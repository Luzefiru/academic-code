import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class RainbowTableGenerator {
    public static void main(String[] args) throws IOException, NoSuchAlgorithmException {
        // Change parameters here
        String charset = "abcdefghijklmnopqrstuvwxyz";
        int minLength = 1; // Min chars
        int maxLength = 6; // Max chars

        generateRainbowTable(charset, minLength, maxLength);
    }

    public static void generateRainbowTable(String charset, int minLength, int maxLength)
        throws IOException, NoSuchAlgorithmException {
    String filename = "rainbow_table.txt";
    BufferedWriter writer = new BufferedWriter(new FileWriter(filename));

    ExecutorService executor = Executors.newFixedThreadPool(4); // Adjust the number of threads as needed

    for (int length = minLength; length <= maxLength; length++) {
        for (char character : charset.toCharArray()) {
            final String prefix = String.valueOf(character);
            final int finalLength = length; // Create a final copy of 'length'
            executor.execute(() -> {
                try {
                    generateCombinations(writer, charset, prefix, finalLength - 1);
                } catch (IOException | NoSuchAlgorithmException e) {
                    e.printStackTrace();
                }
            });
        }
    }

        executor.shutdown();
        try {
            executor.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        writer.close();
    }

    public static void generateCombinations(BufferedWriter writer, String charset, String prefix, int length)
            throws IOException, NoSuchAlgorithmException {
        if (length == 0) {
            String plaintext = prefix;
            String md5Hash = calculateMD5Hash(plaintext);
            writer.write(md5Hash + ":" + plaintext + "\n");
            return;
        }

        for (char character : charset.toCharArray()) {
            generateCombinations(writer, charset, prefix + character, length - 1);
        }
    }

    public static String calculateMD5Hash(String plaintext) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("MD5");
        byte[] md5HashBytes = md.digest(plaintext.getBytes());

        StringBuilder hexHash = new StringBuilder();
        for (byte b : md5HashBytes) {
            hexHash.append(String.format("%02x", b));
        }

        return hexHash.toString();
    }
}