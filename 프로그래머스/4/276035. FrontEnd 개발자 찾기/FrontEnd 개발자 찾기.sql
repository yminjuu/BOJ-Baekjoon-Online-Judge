-- 코드를 작성해주세요
select d.id, d.email, d.first_name, d.last_name
from developers d, skillcodes s
where s.code & d.skill_code > 0 and s.category='Front End'
group by d.id, d.email, d.first_name, d.last_name
order by 1;