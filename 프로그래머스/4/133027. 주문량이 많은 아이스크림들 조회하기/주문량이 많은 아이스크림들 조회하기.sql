-- 코드를 입력하세요
select g.flavor
from first_half f join (
    select flavor, sum(total_order) as total_order
    from july
    group by flavor
) g on f.flavor=g.flavor
order by f.total_order+g.total_order desc
limit 3;