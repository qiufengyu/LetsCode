from dataclasses import dataclass
from typing import Dict

import os

@dataclass
class Stock():
    """Value class for keeping stock start price, end price and the diff."""
    start_date: str
    start_value: float
    end_date: str
    end_value: float
    diff: float = 0.0


class Solution():
    def __init__(self):
        self.stock_dict: Dict[str, Stock] = {}

    def read_and_filter(self, file: str):
        def _date_formatter(raw_date: str) -> str:
            # Format the raw date from input file to be in YYYY-MM-dd without using datetime module
            # So that the natural order of the string is exactly the order of datetime it represents
            if raw_date:
                year_month_day = raw_date.split('-')
                year = year_month_day[0]
                # padding the month and day with '0' if it has one digit only
                month = year_month_day[1] if len(year_month_day[1]) == 2 else ('0' + year_month_day[1])
                day = year_month_day[2] if len(year_month_day[2]) == 2 else ('0' + year_month_day[2])
                return year + month + day

        def _process_one_line(line: str) -> tuple | None:
            if line and len(line) > 0:
                parts = line.split(',')
                if len(parts) == 5:
                    name, date, value = parts[0], parts[1], parts[3]                
                    try:
                        value_float = float(value)
                        date_string = _date_formatter(date)
                        return (name, date_string, value_float)
                    except ValueError or TypeError as e:
                        # print('Invalid number, ignore')
                        return None
            return None
        
        if os.path.isfile(file):
            with open(file, 'r', encoding='utf-8') as f:
                for line in f:
                    result = _process_one_line(line)
                    if result:
                        name, date, value = result[0], result[1], result[2]
                        if name in self.stock_dict:
                            stock : Stock= self.stock_dict[name]
                            if date < stock.start_date:
                                stock.start_date = date
                                stock.start_value = value
                                stock.diff = stock.end_value - value
                            elif date > stock.end_date:
                                stock.end_date = date
                                stock.end_value = value
                                stock.diff = value - stock.start_value
                        else:
                            self.stock_dict[name] = Stock(date, value, date, value)
        else:
            print('Invalid file input.')
            exit(1)


    def largest_absolute_increase(self, file: str):
        # get all date in the dict and find the one with largest absolute increase
        self.read_and_filter(file)
        largest_absolute_increase = -1.0
        # in case more than one stocks share same largest absolute increase
        stock_names = []
        for k in self.stock_dict:
            v = self.stock_dict[k]
            if v.diff >= 0.0 and v.start_date != v.end_date:
                if v.diff > largest_absolute_increase:
                    stock_names = [k]
                    largest_absolute_increase = v.diff
                elif v.diff == largest_absolute_increase:
                    stock_names.append(k)
        if len(stock_names) > 0:
            for s in stock_names:
                print(f'公司: {s}, 股价增值: {largest_absolute_increase:.6f}')
        else:
            print('nil')        


if __name__ == '__main__':
    sol = Solution()
    sol.largest_absolute_increase('values.csv')
