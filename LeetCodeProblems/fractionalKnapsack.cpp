class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,[&](Item& a, Item& b){
            return ((a.value*b.weight)>(b.value*a.weight)); 
            // IMP AF: ALWAYS DO CROSS MULTIPLICATION INSTEAD OF DIVISION
        });
        double money=0;
        for(int i=0;i<n;i++)
        {
           if(W>=arr[i].weight){
               W=W-arr[i].weight;
               money+=double(arr[i].value);
           }
           else{
               money+= W*(double(arr[i].value)/double(arr[i].weight));
               W=0;
           }
        }
        return money;
    }
        
};