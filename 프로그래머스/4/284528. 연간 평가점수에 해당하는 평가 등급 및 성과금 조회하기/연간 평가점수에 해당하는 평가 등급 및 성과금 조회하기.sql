with money as (
    select emp_no,
    case when avg(score)>=96 then 'S'
    when avg(score)>=90 then 'A'
    when avg(score)>=80 then 'B'
    else 'C' end as grade
    from hr_grade
    group by emp_no, year
)
select emp_no, emp_name, grade, (sal * (
    case when grade='S' then 20
    when grade='A' then 15
    when grade='B' then 10
    else 0 end
) / 100) as bonus
from hr_employees join money using (emp_no)
order by 1;