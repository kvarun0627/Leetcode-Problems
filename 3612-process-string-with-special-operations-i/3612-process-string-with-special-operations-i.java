class Solution 
{
    String removeLastChar(String str) 
    {
        if (str == null || str.isEmpty()) 
        {
            return str;
        }
        return str.substring(0, str.length() - 1);
    }

    String reverseString(String str) 
    {
       return new StringBuilder(str).reverse().toString();
    }

    String duplicate(String str) 
    {
        return str + str;
    }

    public String processStr(String s) 
    {
      String str = "";

        for (int i = 0; i < s.length(); i++) 
        {
            char ch = s.charAt(i);

            if (ch == '*') {
                str = removeLastChar(str);
            } else if (ch == '#') {
                str = duplicate(str);
            } else if (ch == '%') {
                str = reverseString(str);
            } else {
                str = str + ch;
            }
        }
      return str;
    }
}