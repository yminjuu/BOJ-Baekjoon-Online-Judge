-- 코드를 입력하세요
SELECT USER_ID, PRODUCT_ID
FROM ONLINE_SALE as A
WHERE (
    SELECT COUNT(*)
    FROM ONLINE_SALE as O
    WHERE O.USER_ID = A.USER_ID AND O.PRODUCT_ID= A.PRODUCT_ID
) > 1
GROUP BY USER_ID, PRODUCT_ID
ORDER BY A.USER_ID, A.PRODUCT_ID DESC;

# unique 한 걸 제외한다