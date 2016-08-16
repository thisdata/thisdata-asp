# thisdata-asp
A Classic ASP wrapper for tracking events to the ThisData API

## Setup
Include `thisdata.inc` at the top of your login.asp or similar authentication page

```
<!--#include file="thisdata.inc"-->
```

Enter your ThisData API key into the `api_key` variable in `thisdata.inc`.


## Track login events
You will track events using the `TrackViaThisData(verb, userId, name, email)` sub
which is found in the `thisdata.inc` file.

Find the place in your login script where a user is authenticated.

If authentication is successfull then track a `log-in` action.

If authentication fails track `log-in-denied`

```
<%
    TrackViaThisData "log-in", "user53", "John Titor", "john@titor.com"
%>
```

## Verbs
For a complete list of verbs that you can track see http://help.thisdata.com/docs/verbs

## Documentation
For complete API documentation see http://help.thisdata.com