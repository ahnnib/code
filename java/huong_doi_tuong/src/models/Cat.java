package models;

public class Cat {
    // class: là đại diện cho các Object có chung những thuộc tính cơ bản
    private String ten;
    private int soChan;
    private String mauLong;
    private int doTuoi;

    // hàm khởi tạo
    public Cat() { // thuoc tinh mac dinh
        ten = "dfkjdkfjdf";
        soChan = 4;
        mauLong = "Trắng";
        doTuoi = 1;
    }
    // hàm khởi tạo có thuộc tính -> đưa tham số vào được
    // this: đại diện cho lớp hiện tại
    public Cat(String ten, int soChan, String mauLong, int doTuoi) {
        this.ten = ten;
        this.soChan = soChan;
        this.mauLong = mauLong;
        this.doTuoi = doTuoi;
    }

    Arrays.sort(a, new Comparator<Cat>() {
        public int compare(Cat o1, Cat o2) { // return x > 0 neu muon doi cho
            // o1 .. o2
            if (o1.getsoChan() > o2.getsoChan()) return 1;
            else return -1;

            // return o1.getsoChan() - o2.getsoChan();
        }
    });

    public String toString() {
        return "Ten = " + ten + ", soChan = " + soChan + ", mauLong = " + mauLong + ", doTuoi = " + doTuoi;
    }

    private void namNgu() {
        System.out.println(ten + " đang ngủ");
    }
    void an() {
        System.out.println(ten + " đang ăn");
        namNgu();
    }
    void tam() {
        System.out.println(ten + " đang tắm");
    }

    public void setTen(String ten) {
        this.ten = ten;
    }
    public String getTen() {
        return ten;
    }
}
