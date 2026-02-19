-- 코드를 입력하세요
SELECT f.flavor
from july j join first_half f on j.flavor = f.flavor
group by f.flavor
order by sum(j.total_order)+f.total_order desc
limit 3;

# select *
# from first_half;