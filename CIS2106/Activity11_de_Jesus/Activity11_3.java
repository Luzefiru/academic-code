package Activity11_de_Jesus;

public class Activity11_3 {
  public static void main(String[] args) {
    CreditCard shopeePayment = new CreditCard("1234123412341234", 1000.0);
    try {
      shopeePayment.processPayment(1100.0);
    } catch (Error e) {
      System.out.println(e.getMessage());
      shopeePayment.processPayment(1000.0);
    }
    shopeePayment.refund("Broken product");
  }

  public static interface PaymentMethod {
    public Double refund(String reason);

    public Boolean processPayment(Double amountToPay) throws Error;
  }

  public static class CreditCard implements PaymentMethod {
    public Double paymentTarget, amountPaid;
    public Boolean isCompleted;
    String accountNumber;

    public CreditCard(String accountNumber, Double paymentTarget) {
      if (accountNumber.length() != 16) {
        throw new Error("ERR: Credit card must have 16 digits.");
      }
      this.accountNumber = accountNumber;
      this.paymentTarget = paymentTarget;
      this.amountPaid = 0.0;
      this.isCompleted = false;
    }

    public Double refund(String reason) {
      Double toReturn = this.amountPaid;
      this.amountPaid = 0.0;
      this.isCompleted = false;
      System.out.println("Refunded payment! Due to: " + reason);
      System.out.println("Amount is credited to card number: " + this.accountNumber);
      return toReturn;
    }

    public Boolean processPayment(Double amountToPay) throws Error {

      if (!amountToPay.equals(this.paymentTarget)) {
        throw new Error("Must pay the exact amount!");
      }

      this.amountPaid = amountToPay;
      this.isCompleted = true;

      return true;
    }
  }

  public static class PayPal implements PaymentMethod {
    public Double paymentTarget, amountPaid;
    public Boolean isCompleted;
    String accountNumber, recepientName;

    public PayPal(String accountNumber, String recepientName, Double paymentTarget) {
      if (accountNumber.length() != 16) {
        throw new Error("ERR: Credit card must have 16 digits.");
      }
      this.accountNumber = accountNumber;
      this.recepientName = recepientName;
      this.paymentTarget = paymentTarget;
      this.amountPaid = 0.0;
      this.isCompleted = false;
    }

    public Double refund(String reason) {
      Double toReturn = this.amountPaid;
      this.amountPaid = 0.0;
      this.isCompleted = false;
      System.out.println("Refunded payment! Due to: " + reason);
      System.out.println("Amount is refunded from: " + this.recepientName);
      System.out.println("Amount is credited to card number: " + this.accountNumber);
      return toReturn;
    }

    public Boolean processPayment(Double amountToPay) throws Error {
      if (amountToPay != this.paymentTarget) {
        throw new Error("Must pay the exact amount!");
      }

      this.amountPaid = amountToPay;
      this.isCompleted = true;
      System.out.println("Amount paid to recepient: " + this.amountPaid);

      return true;
    }
  }

  public static class Bitcoin implements PaymentMethod {
    public Double paymentTarget, amountPaid;
    public Boolean isCompleted;
    String sourceAddress, destinationAddress;

    public Bitcoin(String sourceAddress, String destinationAddress, Double paymentTarget) {
      if (sourceAddress.length() < 26 || sourceAddress.length() > 35) {
        throw new Error("ERR: Must provide a valid Bitcoin address!");
      }
      this.destinationAddress = destinationAddress;
      this.paymentTarget = paymentTarget;
      this.amountPaid = 0.0;
      this.isCompleted = false;
    }

    public Double refund(String reason) {
      Double toReturn = this.amountPaid;
      this.amountPaid = 0.0;
      this.isCompleted = false;
      System.out.println("Refunded payment! Due to: " + reason);
      System.out.println("Amount is refunded from: " + this.destinationAddress);
      System.out.println("Amount is credited to address: " + this.sourceAddress);
      return toReturn;
    }

    public Boolean processPayment(Double amountToPay) throws Error {
      if (amountToPay != this.paymentTarget) {
        throw new Error("Must pay the exact amount!");
      }

      this.amountPaid = amountToPay;
      this.isCompleted = true;
      System.out.println("Amount paid to address: " + this.amountPaid);

      return true;
    }
  }
}
