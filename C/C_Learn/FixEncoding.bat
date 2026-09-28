@echo off
setlocal
chcp 65001 >nul

rem Fix Chinese text encoding for the project files under this BAT file's directory.
rem Close Visual Studio before running this script so project files are not locked.

powershell.exe -NoProfile -ExecutionPolicy Bypass -Command "$root = '%~dp0'.TrimEnd('\'); $excluded = '\\.vs\\|\\x64\\|\\Debug\\|\\Release\\|\\bin\\|\\obj\\'; $extensions = '.c','.cc','.cpp','.cxx','.h','.hh','.hpp','.hxx','.rc'; $files = @(Get-ChildItem -LiteralPath $root -Recurse -File -Force | Where-Object { $_.FullName -notmatch $excluded -and $_.Extension.ToLowerInvariant() -in $extensions }); $gbk = [System.Text.Encoding]::GetEncoding(936); $converted = 0; $skipped = 0; foreach ($file in $files) { try { $bytes = [System.IO.File]::ReadAllBytes($file.FullName); if ($bytes -contains 0) { $skipped++; continue }; if ($bytes.Length -ge 3 -and $bytes[0] -eq 0xEF -and $bytes[1] -eq 0xBB -and $bytes[2] -eq 0xBF) { $text = (New-Object System.Text.UTF8Encoding($false,$true)).GetString($bytes,3,$bytes.Length-3) } else { $text = $null; $utf8 = $true; try { $text = (New-Object System.Text.UTF8Encoding($false,$true)).GetString($bytes) } catch { $utf8 = $false }; if (-not $utf8) { $text = $gbk.GetString($bytes) } }; [System.IO.File]::WriteAllBytes($file.FullName, $gbk.GetBytes($text)); $converted++ } catch { Write-Host ('FAILED: ' + $file.FullName + ' - ' + $_.Exception.Message) -ForegroundColor Red } }; Write-Host ('Source files converted to GBK (code page 936): ' + $converted); Write-Host ('Skipped binary: ' + $skipped); Write-Host 'Fix done.'"

if errorlevel 1 (
	echo Encoding repair failed.
	pause
	exit /b 1
)

echo.
echo Encoding unified to GBK (code page 936). Reopen the solution now.
pause
endlocal
