import java.util.Scanner;

public class Activity_Zodiac_Sign {
  public static final String VALID_MONTHS = "January February March April May June July August September October November December";

  public static void main(String[] args) {
    Scanner get = new Scanner(System.in);
    String month = null;
    int day = -1;

    // Get month & day of user
    while (month == null) {
      System.out.print("What's your birth month? (Capitalized) ");
      String inp = get.nextLine();
      if (VALID_MONTHS.contains(inp)) {
        month = inp;
      }
    }

    while (day == -1) {
      System.out.print("What's your birth day? ");
      int inp = Integer.valueOf(get.next());
      if (1 <= inp && inp <= 31) {
        day = inp;
      }
    }

    get.close();

    // Print zodiac sign
    System.out.println("Your zodiac sign is: " + getZodiacSign(month, day));
  }

  public static String getZodiacSign(String month, int day) {
    String zodiac = "Not in range";
    if ("March".contains(month) && day >= 21 || "April".contains(month) && day <= 19) {
      zodiac = "Aries";
    } else if ("April".contains(month) && day >= 20 || "May".contains(month) && day <= 20) {
      zodiac = "Taurus";
    } else if ("May".contains(month) && day >= 21 || "June".contains(month) && day <= 20) {
      zodiac = "Gemini";
    } else if ("June".contains(month) && day >= 21 || "July".contains(month) && day <= 22) {
      zodiac = "Cancer";
    } else if ("July".contains(month) && day >= 23 || "August".contains(month) && day <= 22) {
      zodiac = "Leo";
    } else if ("August".contains(month) && day >= 23 || "Septemer".contains(month) && day <= 22) {
      zodiac = "Virgo";
    } else if ("September".contains(month) && day >= 23 || "October".contains(month) && day <= 22) {
      zodiac = "Libra";
    } else if ("October".contains(month) && day >= 23 || "November".contains(month) && day <= 21) {
      zodiac = "Scorpio";
    } else if ("November".contains(month) && day >= 22 || "December".contains(month) && day <= 21) {
      zodiac = "Sagittarius";
    } else if ("December".contains(month) && day >= 22 || "January".contains(month) && day <= 19) {
      zodiac = "Capricorn";
    } else if ("January".contains(month) && day >= 20 || "February".contains(month) && day <= 18) {
      zodiac = "Aquarius";
    } else if ("February".contains(month) && day >= 19 || "March".contains(month) && day <= 20) {
      zodiac = "Pisces";
    }

    return zodiac;
  }
}
