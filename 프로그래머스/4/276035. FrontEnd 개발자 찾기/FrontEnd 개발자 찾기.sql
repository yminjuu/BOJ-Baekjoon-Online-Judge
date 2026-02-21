-- 코드를 작성해주세요
select id, email, first_name, last_name
from developers
where exists (
    select code
    from skillcodes
    where skill_code & code > 0 and category='Front End'
)
order by 1;