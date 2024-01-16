package Activity11_de_Jesus;

public class Activity11_1 {
  public static void main(String[] args) {
    SavingsAccount mySavingsAccount = new SavingsAccount(1000.50, 100.0);
    CheckingAccount myCheckingAccount = new CheckingAccount(5000.0);

    try {
      myCheckingAccount.payBill("USC-TC Registrar", 9000.0);
    } catch (Error e) {
      System.out.println(e.getMessage());
    }

    myCheckingAccount.payBill("USC-TC Registrar", 5000.0);
    System.out.println(String.format("My new checking account balance is: %.2f", myCheckingAccount.getBalance()));
    mySavingsAccount.deposit(2000.0);
    System.out.println(String.format("My new savings account balance is: %.2f", mySavingsAccount.getBalance()));
    System.out.println(String.format("Withdrew: %.2f from my savings account.", mySavingsAccount.withdraw(100.0)));
    System.out.println(String.format("My new savings account balance is: %.2f", mySavingsAccount.getBalance()));
  }

  public static abstract class Account {
    protected Double balance;

    public Account(Double startingBalance) {
      this.balance = startingBalance;
    }

    public Double withdraw(Double amount) throws Error {
      if (this.balance >= amount) {
        this.balance -= amount;
        return amount;
      } else {
        throw new Error("BAL_ERR: Not enough funds to finalize transaction.");
      }
    }

    public void deposit(Double amount) {
      this.balance += amount;
    }

    public Double getBalance() {
      return this.balance;
    }
  }

  public static class SavingsAccount extends Account {
    private Double withdrawalLimit;

    public SavingsAccount(Double startingBalance, Double withdrawalLimit) {
      super(startingBalance);
      this.withdrawalLimit = withdrawalLimit;
    }

    @Override
    public Double withdraw(Double amount) throws Error {
      if (amount > this.withdrawalLimit) {
        throw new Error("AMT_ERR: Amount exceeds withdrawal limit.");
      }

      if (this.balance < amount) {
        throw new Error("BAL_ERR: Not enough funds to finalize transaction.");
      }

      this.balance -= amount;
      return amount;
    }
  }

  public static class CheckingAccount extends Account {
    public CheckingAccount(Double startingBalance) {
      super(startingBalance);
    }

    public void payBill(String accountName, Double amount) throws Error {
      if (this.balance < amount) {
        throw new Error("BAL_ERR: Not enough funds to finalize transaction.");
      }

      this.balance -= amount;
      System.out.println(String.format("Successfully paid %.2f to account named: %s.", amount, accountName));
    }
  }
}
