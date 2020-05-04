import java.util.Scanner;

public class robe{
    public static String mainParagraph = "";
    public static String word = "";
    public static String replacedWord = "";
    public static String newString = "";
    static Scanner in = new Scanner(System.in);

    public static void reciever(){
        mainParagraph = mainParagraph.concat(in.nextLine());
        mainParagraph = mainParagraph.concat(" "); 
    }

    public static void recieveSearchWord(){
        word = in.nextLine();
    }

    public static void recieveRplacedWord() {
        replacedWord = in.nextLine();
    }
    
    public static void main(String[] args){
    int counter = 0;
    
    System.out.println("Please enter the first paragraph: ");
    reciever();

    System.out.println("Please enter the second paragraph: ");
    reciever();

    System.out.println("Please enter the third paragraph: ");
    reciever();

    System.out.print("Please enter the word to be searched for : ");
    recieveSearchWord();

    System.out.print("Please enter the to be used as a replacement: ");
    recieveRplacedWord();

    System.out.println("Spliting the paragraph and searching for a value...........");
    String[] arr = mainParagraph.split("\\s");

    for(int i =0; i<arr.length; i++){
        String temp  =arr[i].replace(".", "");
        System.out.print(temp + " ");

        if (arr[i].equals(" "))
            continue;

        if (word.equals(temp) ){
            counter = counter + 1;
            arr[i] = replacedWord;
        }
            
    }

    System.out.println(word + " has be apeared in the paragraph - " + counter + " times");
    
    System.out.println("Concatinating....................");

    for (int i=0; i < arr.length; i++) {
        newString = newString.concat(arr[i]);
        newString = newString.concat(" ");
    }

    System.out.println("The Final Text will be the following");
    System.out.println(newString);
        
    }


    

}

