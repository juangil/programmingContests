
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.HashMap;

public class shares {
    
    static class Scanner
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
        
        public String nextLine()
        {
            try
            {
                return br.readLine();
            }
            catch(Exception e)
            {
                throw(new RuntimeException());
            }
        }
        
        public String next()
        {
            while(!st.hasMoreTokens())
            {
                String l = nextLine();
                if(l == null)
                    return null;
                st = new StringTokenizer(l);
            }
            return st.nextToken();
        }
        
        public int nextInt()
        {
            return Integer.parseInt(next());
        }
        
        public long nextLong()
        {
            return Long.parseLong(next());
        }
        
        public double nextDouble()
        {
            return Double.parseDouble(next());
        }
        
        public int[] nextIntArray(int n)
        {
            int[] res = new int[n];
            for(int i = 0; i < res.length; i++)
                res[i] = nextInt();
            return res;
        }
        
        public long[] nextLongArray(int n)
        {
            long[] res = new long[n];
            for(int i = 0; i < res.length; i++)
                res[i] = nextLong();
            return res;
        }
        
        public double[] nextDoubleArray(int n)
        {
            double[] res = new double[n];
            for(int i = 0; i < res.length; i++)
                res[i] = nextLong();
            return res;
        }
        public void sortIntArray(int[] array)
        {
            Integer[] vals = new Integer[array.length];
            for(int i = 0; i < array.length; i++)
                vals[i] = array[i];
            Arrays.sort(vals);
            for(int i = 0; i < array.length; i++)
                array[i] = vals[i];
        }
        
        public void sortLongArray(long[] array)
        {
            Long[] vals = new Long[array.length];
            for(int i = 0; i < array.length; i++)
                vals[i] = array[i];
            Arrays.sort(vals);
            for(int i = 0; i < array.length; i++)
                array[i] = vals[i];
        }
        
        public void sortDoubleArray(double[] array)
        {
            Double[] vals = new Double[array.length];
            for(int i = 0; i < array.length; i++)
                vals[i] = array[i];
            Arrays.sort(vals);
            for(int i = 0; i < array.length; i++)
                array[i] = vals[i];
        }

        public String[] nextStringArray(int n) 
        {   
            String[] vals = new String[n];
            for(int i = 0; i < n; i++)
                vals[i] = next();
            return vals;
        }
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int C, N, P, buy[], sell[], buyPackage[], profitPackage[], ai, ti, R, sj, qj, caso=0;
    static ArrayList<Integer> profitFixed, costFixed;

    public static void main(String args[]) {
        Scanner s = new Scanner();

        buy = new int[510];
        sell = new int[510];

        caso = 0;
        while (true) {
            
            try {
                C = s.nextInt();                
            }
            catch (NumberFormatException nfe) {
                break;
            }

            // if (caso > 0) System.out.println();
            // ++caso;

            N = s.nextInt();
            P = s.nextInt();

            for (int i=0 ; i<N ; i++) {
                ai = s.nextInt();
                ti = s.nextInt();

                buy[i]  = ai;
                sell[i] = ti;
            }

            profitFixed = new ArrayList<Integer>();
            costFixed = new ArrayList<Integer>();

            for (int i=0 ; i<P ; i++) {
                int totalBuy, totalSell;
                totalBuy = totalSell = 0;
                R = s.nextInt();
                for (int j=0 ; j<R ; j++) {
                    sj = s.nextInt();
                    qj = s.nextInt();

                    totalBuy  += (buy[sj-1] * qj);
                    totalSell += (sell[sj-1] * qj);
                }

                if ((totalSell - totalBuy) > 0 && totalBuy <= C) {
                    costFixed.add(totalBuy);
                    profitFixed.add(totalSell - totalBuy);
                }
            }


            int gcdOfPacks = costFixed.get(0);

            for (int i=1 ; i<costFixed.size() ; i++)
                gcdOfPacks = gcd(gcdOfPacks, costFixed.get(i));

            for (int p=0 ; p<costFixed.size() ; p++) {
                costFixed.set(p, costFixed.get(p) / gcdOfPacks);
            }

            C = (int)Math.floor(C / gcdOfPacks);
            System.out.println(C);
            int dp[][] = new int[2][C+1];

            // BASE CASES...
            dp[0][0] = 0;
            for (int i=0 ; i<=C ; i++)
                dp[0][i] = 0;

            // Now the dp
            boolean flag = true;
            int curr, prev;
            System.out.println(costFixed.size());
            for (int p=0 ; p<costFixed.size() ; p++) {
                curr = flag ? 1 : 0;
                prev = flag ? 0 : 1;
                for (int c=0 ; c<=C ; c++) {
                    if (costFixed.get(p) > c)
                        dp[curr][c] = dp[prev][c];
                    else
                        dp[curr][c] = Math.max(dp[prev][c], profitFixed.get(p) + dp[prev][c - costFixed.get(p)]);
                }
                flag = !flag;
            }

            System.out.println(dp[flag ? 0 : 1][C]);
        }
    }
}
