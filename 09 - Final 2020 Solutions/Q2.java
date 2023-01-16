/*
 * Write a static Java method that takes an integer as a parameter and returns a string that contains the 
 * binary represation of this integer. 
 * If the integer is 21, the returned string is "10101"
 */

class Q2{
    static String getBinary(int value){
        String binaryRev = "";

        while(value > 1){
            binaryRev += (value % 2);
            value /= 2;
        }
        binaryRev += value;
        
        String binary = "";
        for(int idx = binaryRev.length() - 1; idx >= 0 ; idx--)
            binary += binaryRev.charAt(idx);
            
        return binary;
    }
}
