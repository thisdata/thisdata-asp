<%
' This sub will log event data to the ThisData API for risk profiling
' If emails are enabled in your ThisData account and the risk of a
' log-in type of event is high then an alert email will be sent to the user
'
' For detailed documentation see http://help.thisdata.com
'
' verb: A string that represents the action
'       e.g. "log-in", "log-in-denied", "password-reset"
'       http://help.thisdata.com/docs/verbs
'
' userId: A string that uniquely identifiers a user
' name: The full name of the user
' email: The email address of the user
'
' Returns: Nothing
'
' Usage: TrackViaThisData "log-in", "user1234", "John Titor", "john@titor.com"
'
Sub TrackViaThisData(verb, userId, name, email)
    On Error Resume Next   'enable error handling

    Dim http, url, api_key, payload, ip

    ' A valid ThisData API key
    api_key = "xxxxxxxxx"

    ' ThisData API Endpoint
    url = "https://api.thisdata.com/v1/events?api_key=" & api_key

    ' Fetch users IP address
    ip = Request.ServerVariables("HTTP_X_FORWARDED_FOR")
    If ip = "" Then
        ip = Request.ServerVariables("REMOTE_ADDR")
    End If

    ' Json payload to send to ThisData
    payload = "{" &_
        """ip"" : """ & ip & """," &_
        """verb"" : """ & verb & """," &_
        """user_agent"" : """ & Request.ServerVariables("HTTP_USER_AGENT") & """," &_
        """user"" : {" &_
            """id"" : """ & userId & """," &_
            """name"" : """ & name & """," &_
            """email"" : """ & email & """" &_
        "}" &_
    "}"

    Set http = CreateObject("Msxml2.ServerXMLHTTP")

    http.open "POST", url, False
    http.setRequestHeader "Content-Type", "application/json"
    http.send payload

    'If http.Status <> 200 Then
        ' Add custom error logger
        ' Response.Write("Status: " & http.StatusText)
        ' Response.Write("Response: " & http.ResponseText)
    'End If

    'If Err Then
        ' Add custom error logger
        ' Response.Write("Error: " & Err.Description)
    'End If
    On Error Goto 0 'disable error handling
End Sub
%>