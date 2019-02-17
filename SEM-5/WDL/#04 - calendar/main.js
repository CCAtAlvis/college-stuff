let years = [2016, 2017, 2018, 2019, 2020],
    monthsJson = { 
        "Jan": 0, "Feb": 1, "March": 2, "April": 3, "May": 4, "June":5 , "July":6 , "Aug": 7, "Sep": 8, "Oct": 9, "Nov": 10, "Dec": 11
    },
    daysInMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31],
    days = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"];

let yearDOM =  document.getElementById("year"),
    monthDOM = document.getElementById("month");
    calendarDOM = document.getElementById("calendar");

years.forEach(e => {
    yearDOM.options[yearDOM.options.length] = new Option(e, e);
});

for (e in monthsJson) {
    monthDOM.options[monthDOM.options.length] = new Option(e, e);
}

const GetMyCalendar = (e) =>  {
    e.preventDefault();
    calendarDOM.innerHTML = "";

    let year = parseInt(yearDOM.value);
    let month = monthsJson[monthDOM.value];
    let noOfDays = daysInMonth[month];

    if((year%4 == 0 && year%100 != 0) || year%400 == 0) {
        if(month == 1)
            noOfDays++;
    }

    let d = new Date(year, month);

    let calendarHTML = "<tr>";
    days.forEach(e => {
        calendarHTML += "<td>" + e + "</td>";
    });
    calendarHTML += "</tr>";

    let counter = 0;

    for(i=0; i<d.getDay(); i++) {
        if(i==0)
            calendarHTML += "<tr>";

        calendarHTML += "<td>-</td>";
        counter++;
    }

    for(i=1;i<=noOfDays;i++){
        if(counter == 0)
            calendarHTML += "</tr><tr>";
        // else if(counter == 6)
        //     calendarHTML += "</tr>";

        calendarHTML += "<td>" + i + "</td>";

        counter = (counter+1)%7;
    }

    if(counter != 6)
        calendarHTML += "</tr>";

    calendarDOM.innerHTML = calendarHTML;
}
