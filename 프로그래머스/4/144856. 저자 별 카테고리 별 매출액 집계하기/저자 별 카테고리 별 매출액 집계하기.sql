-- 코드를 입력하세요
# 2022년 1월 기준 책 별 판매량 + 책 별 author id
select AUTHOR_ID, AUTHOR_NAME, CATEGORY, sum(a.sales*b.price) as TOTAL_SALES
from
(SELECT BOOK_ID, SALES
FROM BOOK_SALES
WHERE SALES_DATE LIKE ('2022-01%')) a natural join BOOK b natural join AUTHOR c
group by c.author_name, category
order by 1, 3 desc;
