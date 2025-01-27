vector<int> findTwoElement(vector<int>& arr) {
       long n = arr.size();
    
    
    long aSumN = (n * (n + 1)) / 2;
   
    long aSumN_2 = (n * (n + 1) * (2 * n + 1)) / 6;

    long obSumN = 0;   
    long obSumN_2 = 0;  

   
    for (long val : arr) {
        obSumN += val;
        obSumN_2 += (val * val);
    }

   
    long val1 = aSumN - obSumN;           
    long val2 = aSumN_2 - obSumN_2;      
    val2 = val2 / val1;                  
    int missing = (val1 + val2) / 2;
    int repeating = val2 - missing;

    return {repeating, missing};
    }