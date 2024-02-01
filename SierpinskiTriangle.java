import java.util.Scanner;

public class SierpinskiTriangle {

    // Creates a 2x2 matrix of ASCII char '*' in the shape of a Sierpinski triangle
    private static void asciiTri(char[][] matrix, int row, int col, int size) {
        // Base case, when size is 1
        if (size == 1) {
            matrix[row][col] = '*';
        } else {
            // Recursive case for other sizes
            int newSize = size / 2;
            asciiTri(matrix, row, col, newSize); // Top of the triangle
            asciiTri(matrix, row + newSize, col - newSize, newSize); // Left side of the triangle
            asciiTri(matrix, row + newSize, col + newSize, newSize); // Right side of the triangle
        }
    }

    // Uses the 2x2 matrix created with proper char '*' and prints it
    private static void printTri(char[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your desired triangle iterations as n (n >= 0): ");
        int n = scanner.nextInt(); // Gets number n for iterations

        if (n < 0) {
            System.out.println("No negative nums");
            scanner.close();
            return;
        }

        int size = (int) Math.pow(2, n); // The height of the triangle after n iterations is 2^n
        // The width of the triangle is 2 * height - 1 to keep the triangle centered

        char[][] canvas = new char[size][size * 2 - 1]; // Creates matrix to draw the triangle

        // Fills in the empty matrix to use and fill with '*'
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size * 2 - 1; j++) {
                canvas[i][j] = ' ';
            }
        }

        // Fills in the matrix with the proper '*'
        asciiTri(canvas, 0, size - 1, size);
        // Prints the matrix
        printTri(canvas);

        scanner.close();
    }
}
