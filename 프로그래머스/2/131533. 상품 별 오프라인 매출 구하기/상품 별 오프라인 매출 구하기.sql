-- 코드를 입력하세요
SELECT PRODUCT_CODE, SUM(SALES_AMOUNT)*PRICE AS SALES
FROM PRODUCT NATURAL JOIN OFFLINE_SALE
GROUP BY 1
ORDER BY 2 DESC, 1;