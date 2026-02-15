select CAR_ID, case when
exists
(
    select 1 # 상수 반환
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY sub
    where '2022-10-16' between start_date and end_date and
    main.CAR_ID=sub.CAR_ID
) then '대여중'
else '대여 가능' end as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY main
group by CAR_ID
order by 1 desc;