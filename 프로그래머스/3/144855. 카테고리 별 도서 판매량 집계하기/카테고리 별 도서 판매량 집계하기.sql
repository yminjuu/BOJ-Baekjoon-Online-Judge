-- 코드를 입력하세요
SELECT CATEGORY, sum(sales) as TOTAL_SALES
from book natural join book_sales 
where sales_date like ('2022-01%')
group by category
order by 1;