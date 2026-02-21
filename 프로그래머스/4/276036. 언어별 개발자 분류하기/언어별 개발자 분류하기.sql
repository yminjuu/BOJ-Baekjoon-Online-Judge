-- 코드를 작성해주세요
select 
-- grade를 정해서 having 사용하기
case 
    -- 모든 터플에 대해 front end 스킬 존재 여부 확인
    when sum(case when s.category='Front end' then 1 else 0 end) > 0 and d.skill_code & (select code from skillcodes where name='Python') > 0 then 'A'
    when d.skill_code & (select code from skillcodes where name='C#') then 'B'
    when sum(case when s.category='Front end' then 1 else 0 end) > 0 then 'C'
    else 'D'
end as grade
, d.id, d.email
from developers d, skillcodes s
where 
-- 내가 가진 skillcode만 남도록
d.skill_code & s.code > 0
group by d.id, d.skill_code, d.email
having grade < 'D'
order by 1, 2;