-- 코드를 입력하세요
with host as (
SELECT host_id
from places
group by host_id
having count(id)>=2)

select id, name, host_id
from places natural join host
order by 1;