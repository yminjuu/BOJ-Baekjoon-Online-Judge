SELECT CAR_ID, MAX(
    # 이 case는 각 tuple에 대해 적용되고
    case
when date(START_DATE)<= date('2022-10-16') and date(END_DATE)>= date('2022-10-16') then '대여중'
else '대여 가능' 
end) 
    # MAX 함수를 통해 모든 터플의 MAX가 group의 터플로 들어간다
as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
group by CAR_ID
order by 1 desc;