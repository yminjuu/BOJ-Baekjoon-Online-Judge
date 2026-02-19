-- 코드를 입력하세요
SELECT distinct(a.car_id), a.car_type, round(30*a.daily_fee*((100-coalesce(c.discount_rate,0))/100), 0) as fee
from (
    -- 조건 만족 car_id만 뽑은 a 테이블
    select car_id, car_type, daily_fee
    from car_rental_company_car
    where car_type in ('세단', 'SUV') and 
    car_id not in (
        select distinct(car_id)
        from CAR_RENTAL_COMPANY_RENTAL_HISTORY
        where start_date <= '2022-11-30' and end_date >='2022-11-01'
    )
) a left join CAR_RENTAL_COMPANY_DISCOUNT_PLAN c on (a.car_type=c.car_type and c.duration_type = '30일 이상')
where 500000 <= 30*a.daily_fee*((100-coalesce(c.discount_rate,0))/100) and 30*a.daily_fee*((100-coalesce(c.discount_rate,0))/100) < 2000000
order by 3 desc, 2, 1 desc;