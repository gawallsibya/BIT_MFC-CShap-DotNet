<?xml version="1.0" encoding="utf-8"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/">
		<html>
			<body>
				XML 신상정보<br/>
				<table width="400">
					<tr bgcolor="#CCCCCC">
						<td>이름</td>
						<td>직업</td>
						<td>회사</td>
					</tr>
					<xsl:for-each select="Persons/Person">
						<tr>
							<td><xsl:value-of select="이름"/></td>
							<td><xsl:value-of select="직업"/></td>
							<td><xsl:value-of select="회사"/></td>
						</tr>
					</xsl:for-each>
				</table>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>