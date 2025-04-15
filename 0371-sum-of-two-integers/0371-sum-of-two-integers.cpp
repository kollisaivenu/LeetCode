class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0, bitc = 0;
        for(int i=0;i<32;i++){
            int bita = a & 1;
            int bitb = b & 1;
            a = a>>1;
            b = b>>1;
            //cout<<bita<<"\n";
            //cout<<bitb<<"\n";
            if(bita == 1 && bitb == 0 || bita == 0 && bitb == 1){
                //cout<<sum<<"\n";
                if(bitc == 0){
                    sum = sum | (1 << i);
                }
                
            } else if(bita == 1 && bitb == 1){
                if(bitc == 0){
                    bitc = 1;
                } else {
                    sum = sum | (1 << i);
                }
            } else if(bita == 0 && bitb == 0 && bitc == 1){
                sum = sum | (1 << i);
                bitc = 0;
            }
        }
        return sum;
    }
};