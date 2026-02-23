-- 코드를 작성해주세요
with s as (
    select dept_id, round(avg(sal), 0) as avg_sal
    from hr_employees
    group by dept_id
)

select dept_id, dept_name_en, avg_sal
from hr_department natural join s
order by 3 desc;