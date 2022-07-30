# Write your MySQL query statement below
SELECT firstName, lastName, city, state from Person LEFT OUTER JOIN Address ON ( Person.personId = Address.personId );