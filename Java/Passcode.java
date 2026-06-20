public class Passcode {
    public static void main(String[] args) {
        int couponCode = 123456; 
        int sum = 0;

        while (couponCode > 0) {
            sum += couponCode % 10;
            couponCode /= 10;
        }
        }

        while (sum >= 10) {
            int tempSum = 0;
            while (sum > 0) {
                tempSum += sum % 10;
                sum /= 10;
            }
            sum = tempSum;
        }

        if (sum == 7) {
            System.out.println("The coupon code is valid.");
        } else {
            System.out.println("The coupon code is invalid.");
        }
    }
}
