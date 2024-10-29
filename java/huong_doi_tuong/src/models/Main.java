package models;

public class Main {
    public static void main(String[] args) {
        Cat meo_1 = new Cat("Tom", 4, "Den", 5);

        meo_1.setTen("meomeo");
        System.out.println(meo_1.getTen());

        Cat meo_2 = new Cat();
        System.out.println(meo_2.getTen());
        // Cat meo = new Cat();
        // meo.namNgu();

        // buổi sau: học tính kế thừa (inheritance)
        // hàm toString đã được viết đè lên (over-ride)
        System.out.println(meo_1);
    }
}