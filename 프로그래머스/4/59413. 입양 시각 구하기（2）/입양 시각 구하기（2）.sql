-- 코드를 입력하세요
with recursive hours as (
    -- anchor
    select 0 as hour
    union all
    
    select hour+1
    from hours
    where hour<23
)
SELECT hour, sum(case when animal_id is null then 0 else 1 end) as count
from hours left join animal_outs on (hour=hour(datetime))
group by hour
order by 1;