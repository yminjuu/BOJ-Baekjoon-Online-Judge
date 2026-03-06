select grade, id ,email
from (select (
    case
        when skill_code & (select code from skillcodes where name='Python') > 0 and exists (select 1 from skillcodes where category='Front end' and skill_code & code > 0) then 'A'
        when skill_code & (select code from skillcodes where name='C#') > 0 then 'B'
        when exists (select 1 from skillcodes where category='Front end' and skill_code & code > 0) then 'C'
    end
) as grade, id, email
from developers) as a
where grade is not null
order by grade, id;