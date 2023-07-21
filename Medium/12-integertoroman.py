class Solution:
    def intToRoman(self, num: int) -> str:
        """
        It seems like Roman Numerals are created in base-10 groups.

        1 <= n <= 3999, so we have at most 3 groups to consider.
        """

        thousands = num // 1000
        hundreds = (num % 1000) // 100
        tens = (num % 100) // 10
        ones = num % 10


        res = ""

        if thousands != 0:
            res += "M" * thousands

        if hundreds != 0:
            if hundreds == 9:
                res += "CM"
            elif hundreds == 4:
                res += "CD"
            elif hundreds >= 5:
                res += "D" + "C" * (hundreds - 5)
            else:
                res += "C" * hundreds

        if tens != 0:
            if tens == 9:
                res += "XC"
            elif tens == 4:
                res += "XL"
            elif tens >= 5:
                res += "L" + "X" * (tens - 5)
            else:
                res += "X" * tens

        if ones != 0:
            if ones == 9:
                res += "IX"
            elif ones == 4:
                res += "IV"
            elif ones >= 5:
                res += "V" + "I" * (ones - 5)
            else:
                res += "I" * ones

        return res
