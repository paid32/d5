import javax.crypto.*;
import java.util.Scanner;

class DES{
    public static void main(String[] args) throws Exception  {
        Scanner myObj = new Scanner(System.in);
        String  message=myObj.nextLine();
        byte[] myMessage =message.getBytes(); 
        KeyGenerator Mygenerator = KeyGenerator.getInstance("DES");
        SecretKey myDesKey = Mygenerator.generateKey();
        Cipher myCipher = Cipher.getInstance("DES");
        myCipher.init(Cipher.ENCRYPT_MODE, myDesKey);
        byte[] myEncryptedBytes=myCipher.doFinal(myMessage);
        myCipher.init(Cipher.DECRYPT_MODE, myDesKey);
        byte[] myDecryptedBytes=myCipher.doFinal(myEncryptedBytes);
        String encrypteddata=new String(myEncryptedBytes);
        String decrypteddata=new String(myDecryptedBytes);
        System.out.println("Message : "+ message);
        System.out.println("Encrypted - "+ encrypteddata);
        System.out.println("Decrypted Message - "+ decrypteddata);
        myObj.close();
    }
}