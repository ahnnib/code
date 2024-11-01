import Book.Book;

public class App {
    public static void main(String[] args) throws Exception {
        Book book1 = new Book();

        System.out.println(book1);
        book1.input();
        System.out.println(book1);
    }
}
