class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int numberOfBytesToProcess = 0;
        int mask1 = 1 << 7; //10000000
        int mask2 = 1 << 6; //01000000
        
        for (int i = 0; i < data.size(); i++) {
            
            if (numberOfBytesToProcess == 0) {
                //toh starting ke 1 count karlo
                int mask = 1 << 7;
                while ((mask & data[i]) != 0) {
                    // matlab 1 hai
                    numberOfBytesToProcess += 1;
                    mask >>= 1;
                }
                
                //agar starting mein 0 mila mask karke
                //matlab 1 byte character hai
                if (numberOfBytesToProcess == 0) {
                    continue;
                }
                
                //4 se zyada bytes to return false
                //numberOfBytesToProcess 1 hai matlab 1 mila starting mein
                //but data mein matlab single element hai, but single hai
                //toh 0 milna tha to return false
                if (numberOfBytesToProcess > 4 || numberOfBytesToProcess == 1) {
                    return false;
                }
            }
            else {
                if (!((data[i] & mask1) != 0 && (mask2 & data[i]) == 0)) {
                    return false;
                }
            }
            numberOfBytesToProcess -= 1;
        }
        //agar pura array process karliya and nothing to process
        return numberOfBytesToProcess == 0;
    }
};