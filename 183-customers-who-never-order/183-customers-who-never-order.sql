# Write your MySQL query statement below
SELECT name as Customers from Customers WHERE Customers.id NOT IN ( SELECT customerId from Orders );