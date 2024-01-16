package Activity11_de_Jesus;

public class Activity11_2 {
  public static void main(String[] args) {
    Mage merlin = new Mage(0, 1);
    Warrior tryndamere = new Warrior(2, 3);
    Rogue chilchuck = new Rogue(3, 3);

    System.out.println("-  [Merlin] I'll cover you, run towards him & take him down!");
    merlin.useAbility(tryndamere);
    System.out.println("-  [Chilchuck] I got him!");
    chilchuck.useAbility(tryndamere);
    System.out.println("-  [Tryndamere] I'LL NEVER YIELD!");
    tryndamere.useAbility(merlin);
    System.out.println("-  [Chilchuck] You'll have to - finish it yourself Merlin...");
    tryndamere.attack(chilchuck, 20);
    System.out.println("-  [Merlin] Chilchuck - no!");
    merlin.useAbility(tryndamere);
    System.out.println("-  [Tryndamere] I'M NOT DONE!");
    tryndamere.attack(merlin, 20);
  }

  public static abstract class Character {
    public Integer xPos, yPos, healthPoints, mana;

    public Character(Integer startingXPos, Integer startingYPos, Integer startingHp, Integer startingMana) {
      this.xPos = startingXPos;
      this.yPos = startingYPos;
      this.healthPoints = startingHp;
      this.mana = startingMana;
    }

    public void move(Integer xSteps, Integer ySteps) {
      this.xPos += xSteps;
      this.yPos += ySteps;
      System.out.println(String.format("The new position is (%d ,%d)", this.xPos, this.yPos));
    }

    public Integer getHealthPoints() {
      return this.healthPoints;
    }

    public void setHealthPoints(Integer newHealthPoints) {
      this.healthPoints = newHealthPoints;
    }

    public Integer getMana() {
      return this.mana;
    }

    public void setMana(Integer newMana) {
      this.mana = newMana;
    }

    public boolean isDead() {
      return this.healthPoints <= 0;
    }

    public void attack(Character enemy, Integer damage) {
      enemy.setHealthPoints(enemy.getHealthPoints() - damage);
      if (enemy.isDead()) {
        System.out.println(String.format("You did %d damange to the enemy. They are dead.", damage));
      } else {
        System.out.println(
            String.format("You did %d damange to the enemy. Their new HP is: %d.", damage, enemy.getHealthPoints()));
      }
    }

    public void useAbility(Character enemy) {
      System.out.println("The base character has no available abilities!");
    };
  }

  public static class Warrior extends Character {
    private final static Integer WARRIOR_STARTING_HP = 20, WARRIOR_STARTING_MANA = 5;

    public Warrior(Integer startingXPos, Integer startingYPos) {
      super(startingXPos, startingYPos, WARRIOR_STARTING_HP, WARRIOR_STARTING_MANA);
    }

    @Override
    public void useAbility(Character enemy) throws Error {
      if (this.mana >= 5) {
        this.setHealthPoints(WARRIOR_STARTING_HP);
        this.setMana(0);
        System.out.println("You shout to defy death and restore your health points to full.");
      } else {
        throw new Error("ERR: Not enough mana to use ability!");
      }
    };
  }

  public static class Mage extends Character {
    private final static Integer MAGE_STARTING_HP = 10, MAGE_STARTING_MANA = 30;

    public Mage(Integer startingXPos, Integer startingYPos) {
      super(startingXPos, startingYPos, MAGE_STARTING_HP, MAGE_STARTING_MANA);
    }

    @Override
    public void useAbility(Character enemy) throws Error {
      if (this.mana >= 10) {
        this.setMana(this.getMana() - 10);
        System.out.println("You cast a fireball on the enemy!");
        this.attack(enemy, 10);
      } else {
        throw new Error("ERR: Not enough mana to use ability!");
      }
    };
  }

  public static class Rogue extends Character {
    private final static Integer ROGUE_STARTING_HP = 15, ROGUE_STARTING_MANA = 20;

    public Rogue(Integer startingXPos, Integer startingYPos) {
      super(startingXPos, startingYPos, ROGUE_STARTING_HP, ROGUE_STARTING_MANA);
    }

    @Override
    public void useAbility(Character enemy) throws Error {
      if (this.mana >= 5) {
        this.setMana(this.getMana() - 5);
        System.out.println("Using your vampiric blades, you stab the enemy!");
        this.attack(enemy, 5);
        this.setHealthPoints(this.getHealthPoints() + 5);
      } else {
        throw new Error("ERR: Not enough mana to use ability!");
      }
    };
  }
}
