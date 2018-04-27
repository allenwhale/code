class Solution:
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        try:
            x = int(s)
            return True
        except:
            pass
        try:
            x = float(s)
            return True
        except:
            pass
        return False
	
        
