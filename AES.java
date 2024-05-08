import java.security.Key;
import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

public class AES {

    private static final String ALGORITHM = "AES";
    private static final byte[] keyValue = new byte[] { 'T', 'h', 'i', 's', 'I', 's', 'A', 'S', 'e', 'c', 'r', 'e', 't',
            'K', 'e', 'y' };

    public static String encrypt(String data) throws Exception {
        Key key = generateKey();// generation dinamic
        Cipher c = Cipher.getInstance(ALGORITHM);
        c.init(Cipher.ENCRYPT_MODE, key);
        byte[] encVal = c.doFinal(data.getBytes());
        return Base64.getEncoder().encodeToString(encVal);
    }

    private static Key generateKey() throws Exception {
        return new SecretKeySpec(keyValue, ALGORITHM);
    }

    public static String decrypt(String encryptedData) throws Exception {
        Key key = generateKey();
        Cipher c = Cipher.getInstance(ALGORITHM);
        c.init(Cipher.DECRYPT_MODE, key);
        byte[] decodedValue = Base64.getDecoder().decode(encryptedData);
        byte[] decVal = c.doFinal(decodedValue);
        return new String(decVal);
    }

    public static void main(String args[]) {
        try {
            String data = "my name is aryan";
            String encryptedData = encrypt(data);
            String decryptedData = decrypt(encryptedData);
            if (data.equals(decryptedData)) {
                System.out.println("Data is successfully encrypted and decrypted");
            } else {
                System.out.println("Encryption and decryption failed");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}