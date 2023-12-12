import java.util.stream.Stream;

public class Activity8_de_Jesus {
  public static void main(String[] args) {
    String word = "helloWorld";
    // System.out.println(String.format("Reverse of %s: %s\n", word,
    // toReversed(word)));
    System.out.println(String.format("Number of 'l' in %s: %s\n", word, getCharOccurences(word, 'l')));
    // System.out.println(String.format("Uppercase of %s: %s\n", word,
    // toUpper(word)));
    // System.out.println(String.format("Lowercase of %s: %s\n", word,
    // toLower(word)));
    // System.out
    // .println(String.format("A string array of %s with the delimiter 'll': ",
    // word));
    // System.out.print("[ ");
    // for (String str : toStringArray(word, "ll")) {
    // System.out.print(str + " ");
    // }
    // System.out.println("]\n");
    // System.out.println(String.format("%s starts with 'hello'? %s\n", word,
    // stringStartsWith(word, "hello")));
    // System.out.println(String.format("%s starts with '???'? %s\n", word,
    // stringStartsWith(word, "???")));
    // System.out.println(String.format("%s ends with 'World'? %s\n", word,
    // stringEndsWith(word, "World")));
    // System.out.println(String.format("%s ends '!!!' 'World'? %s\n", word,
    // stringEndsWith(word, "!!!")));
  }

  // 1. Write a function that takes a string as input and returns the reversed
  // version of that string using string manipulation methods.
  public static String toReversed(String s) {
    return new StringBuilder(s).reverse().toString();
  }

  // 2. Create a function that counts the occurrences of a specific character in a
  // given string using the charAt() method.
  public static int getCharOccurences(String s, char toCount) {
    return Stream.of(s.split("")).filter(ch -> ch.charAt(0) == toCount).toArray().length;
  }

  // 3. Write a function that converts a string to uppercase and lowercase using
  // the toUpperCase() and toLowerCase() methods.
  public static String toUpper(String s) {
    return s.toUpperCase();
  }

  public static String toLower(String s) {
    return s.toLowerCase();
  }

  // 4. Create a function that splits a string into an array of substrings based
  // on a given delimiter using the split() method.
  public static String[] toStringArray(String s, String del) {
    return s.split(del);
  }

  // 5. Write a function that checks if a given string starts or ends with a
  // specific substring using the startsWith() and endsWith() methods.
  public static boolean stringStartsWith(String s, String prefix) {
    return s.startsWith(prefix);
  }

  public static boolean stringEndsWith(String s, String suffix) {
    return s.endsWith(suffix);
  }
}
