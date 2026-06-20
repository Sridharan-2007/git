public class Grocessary {
    public static void main(String[] args) {
        double price1 = 5000; 
        double price2 = 3000; 
        int quantity1 = 2; 
        int quantity2 = 3; 

        System.out.println("Final Bill for Product 1: " + calculateFinalBill(price1, quantity1));
        System.out.println("Final Bill for Product 2: " + calculateFinalBill(price2, quantity2));

        comparePrices(price1, price2);
    }

    public static double calculateFinalBill(double price, int quantity) {
        double packagingCharge = 750;
        double totalPrice = (price + packagingCharge) * quantity;

        if (totalPrice > 7500) {
            totalPrice *= 0.9; 
        }

        return totalPrice;
    }

    public static void comparePrices(double price1, double price2) {
        if (price1 > price2) {
            System.out.println("Product 1 has a higher price: " + price1);
        } else if (price2 > price1) {
            System.out.println("Product 2 has a higher price: " + price2);
        } else {
            System.out.println("Both products have the same price: " + price1);
        }
    }
}

