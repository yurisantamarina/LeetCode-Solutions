import datetime
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        d = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
        ans = datetime.date(year, month, day)
        return d[ans.weekday()]
