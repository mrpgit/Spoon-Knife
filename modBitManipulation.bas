Attribute VB_Name = "modBitManipulation"
Public Property Get LoWord(ByRef lngThis As Long) As Long

    LoWord = (lngThis And &HFFFF&)

End Property

Public Property Let LoWord(ByRef lngThis As Long, ByVal lngLoWord As Long)
    lngThis = lngThis And Not &HFFFF& Or lngLoWord
End Property

Public Property Get HiWord(ByRef lngThis As Long) As Long

    If (lThis And &H80000000) = &H80000000 Then
        HiWord = ((lngThis And &H7FFF0000) \ &H10000) Or &H8000&
    Else
        HiWord = (lngThis And &HFFFF0000) \ &H10000
    End If

End Property

Public Property Let HiWord(ByRef lngThis As Long, ByVal lngHiWord As Long)

    If (lngHiWord And &H8000&) = &H8000& Then
        lngThis = lngThis And Not &HFFFF0000 Or ((lngHiWord And &H7FFF&) * &H10000) Or &H80000000
    Else
        lngThis = lngThis And Not &HFFFF0000 Or (lngHiWord * &H10000)
    End If

End Property

Public Function PackServerAndChannel(ByVal intServerIndex As Integer, ByVal intChannelIndex As Integer) As Long
Dim lngPackedNumber As Long

    HiWord(lngPackedNumber) = intServerIndex
    LoWord(lngPackedNumber) = intChannelIndex
    PackServerAndChannel = lngPackedNumber

End Function
Public Sub UnPackServerAndChannel(ByRef intServerIndex As Integer, ByRef intChannelIndex As Integer, ByVal lngPackedNumber As Long)
    
    intServerIndex = HiWord(lngPackedNumber)
    intChannelIndex = LoWord(lngPackedNumber)

End Sub
