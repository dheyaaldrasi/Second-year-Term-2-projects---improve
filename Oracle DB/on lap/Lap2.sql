

begin
dbms_output.put_line('Diaa Al-Drasi');
end;
/

BEGIN
dbms_output.put_line('I`m an IT student');
end;
/

begin
dbms_output.put_line('Hello World');
end;
/

begin
dbms_output.put_line('Welcome to heal.');
end;
/




declare
    number1 int := 5;
    number2 int := 5;
begin
        DBMS_OUTPUT.PUT_LINE(number1 * number2);
        DBMS_OUTPUT.PUT_LINE(number1 + number1);

    end;
    /


select * from STUDENTS;

declare
mark number;
name varchar(100);
begin
select GPA, FullName into mark,name from STUDENTS where id=2;
DBMS_OUTPUT.PUT_LINE(mark);
DBMS_OUTPUT.PUT_LINE(name);
end;
/



select * from students;


-- استخدام المتغيرات في التحديث والادخال والحذف 

commit;

