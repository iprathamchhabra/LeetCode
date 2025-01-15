class Solution(object):
    def minimizeXor(self, num1, num2):
        set_bits_num2 = bin(num2).count('1')    
        result = 0
        
        for i in range(31, -1, -1): 
            if set_bits_num2 == 0:
                break
            if num1 & (1 << i): 
                result |= (1 << i)
                set_bits_num2 -= 1
        
        for i in range(32):
            if set_bits_num2 == 0:
                break
            if not (result & (1 << i)):  
                result |= (1 << i)  
                set_bits_num2 -= 1
        
        return result
