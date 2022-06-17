program listreverse;

const N = 10;

type
    List = class
    private
        data: array[1..N] of real;

    public
        size: integer;
        constructor Create;
        procedure PushBack(elem: real);
        function PopBack: real;
        procedure Write;
        procedure Reverse;
    end;

constructor List.Create;
begin
    size := 0;
end;

procedure List.Write;
var i: integer;
begin
    writeln("List elements:");
    for i := 1 to size do
        writeln(data[i]);
end;

procedure List.PushBack(elem: real);
begin
    if size < N then
    begin
        inc(size);
        data[size] := elem;
    end;
end;

function List.PopBack: real;
begin
    if size > 0 then
    begin
        PopBack := data[size];
        dec(size);
    end;
end;

procedure List.Reverse;
var 
i: integer;
tmp: real;
begin
    for i := 1 to size div 2 do 
    begin
        tmp := data[i];
        data[i] := data[size - i + 1];
        data[size - i + 1] := tmp;
    end;
end;

var
l: List;
e: real;
i, s: integer;
begin
    l := List.Create;
    writeln("Input size of list:");
    readln(s);
    writeln("Input list elements:");
    for i := 1 to s do
    begin
        readln(e);
        l.PushBack(e);
    end;
    l.Write;
    l.Reverse;
    l.Write;
    writeln(l.PopBack, l.size);
end.
