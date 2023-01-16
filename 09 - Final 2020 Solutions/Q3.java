import java.util.ArrayList;

/*
 * Design and implement a Comparable Java class to represent a Rational number such as 3/2. 
 * Your class will have the following methods as well as any other methods necessary (setters, getters, etc.)
 */

class Rational implements Comparable<Rational>{
    private int numerator;
    private int denominator;

    static ArrayList<Rational> objects = new ArrayList<>();

    public Rational(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;

        if(denominator == 0)
            
            throw new ArithmeticException("Divided by Zero");

        simpfly();
        objects.add(this);
    }

    private void simpfly(){
        int min = numerator<denominator ? numerator : denominator;
        int max = 1;

        for(int i = 1; i <= min; i++ )
            if(numerator % i == 0 && denominator % i == 0)  
                max = i;
        
        numerator /= max;
        denominator /= max;
    }
    // MOST important thing
    @Override
    public int compareTo(Rational o){
        double f = getNumerator() / getDenominotor();
        double s = o.getNumerator() / o.getDenominotor();

        if (f==s) return 0;
        if (f > s)return 1;

        return -1;
    }

    int getNumerator(){return numerator;}
    void setNumerator(int numerator){this.numerator = numerator;}

    int getDenominotor(){return denominator;}
    void setDenominator(int den){
        if(den == 0)
            throw new ArithmeticException("Divide by zero exception!");
        denominator = den;
    }

    static ArrayList<Rational> getRationalObjects(){return objects;}

    @Override
    public String toString(){

        if(numerator % denominator == 0)
            return numerator/denominator+"";
        
        return numerator+"/"+denominator;
    }

    public Rational mult(Rational o2){
        return new Rational(getNumerator() * o2.getNumerator(), o2.getDenominotor() * getDenominotor());
    }

    public Rational add(Rational o2){
        int o2Num = o2.getNumerator() * getDenominotor();

        int o1Num = o2.getDenominotor() * getNumerator();
        int o1DeNum = o2.getDenominotor() * getDenominotor();

        return new Rational(o1Num + o2Num, o1DeNum);
    }
}

class TestRational{
    static void testIt(){
        Rational r1 = new Rational(10, 20);
        Rational r2 = new Rational(50, 100);
        Rational one = r1.add(r2);
        Rational oneDivFour = r1.mult(r2);

        System.out.println("one : " + one);
        System.out.println("oneDivFour : " + oneDivFour);

        try{
            Rational err = new Rational(10, 0);
        }catch(Exception e){
            System.out.println("1 " + e.getMessage());
        }

        try{
            Rational err = r1.mult(new Rational(0, 0));
        }catch(Exception e){
            System.out.println("2 " + e.getMessage());
        }

        Rational r3 = new Rational(12, 100);
        Rational r4 = new Rational(123, 411);
        Rational r5 = new Rational(32, 123);
        r5 = r3.add(r4);
        System.out.println("r5 : " + r5);

        for(Rational temp : Rational.getRationalObjects())
            System.out.println(temp);
        
    }
}
