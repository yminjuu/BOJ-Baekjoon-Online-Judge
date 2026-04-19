with avg_sal as (
    select dept_id, round(avg(sal),0) as avg_sal
    from hr_employees
    group by dept_id
)

select b.dept_id, b.dept_name_en, a.avg_sal
from avg_sal a join hr_department b on (a.dept_id=b.dept_id)
order by 3 desc;